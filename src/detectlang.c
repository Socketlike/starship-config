#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "config.h"

int strequal(char* str1, char* str2)
{
  if (!str1 || !str2)
    return 0;
  if (strcmp(str1, str2) > 0 || strcmp(str1, str2) < 0)
    return 0;
  else
    return 1;
}

int endswith(char* str, const char* end)
{
  if (!str || !end)
    return 0;
  size_t lenstr = strlen(str);
  size_t lenend = strlen(end);
  if (lenend > lenstr)
    return 0;
  return strncmp(str + lenstr - lenend, end, lenend) == 0;
}

char* matchlang(char* name, int isDir)
{
  const int len = sizeof(lang) / sizeof(lang[0]);
  struct Language *language;
  if (isDir) {
    for (int i = 0; i < len; i++) {
      for (int x = 0; x < sizeof(lang[i].dirmatch) / sizeof(lang[i].dirmatch[0]); x++) {
        language = &lang[i];
        if (language->dirmatch[x] == NULL)
          break;
        if (strequal(language->dirmatch[x], name)) {
          language->count++;
          return language->name;
        }
      }
    }
  } else {
    for (int i = 0; i < len; i++) {
      for (int x = 0; x < sizeof(lang[i].filematch) / sizeof(lang[i].filematch[0]); x++) {
        language = &lang[i];
        if (language->filematch[x] == NULL)
          break;
        if (strequal(language->filematch[x], name)) {
          language->count++;
          return language->name;
        }
      }
      for (int x = 0; x < sizeof(lang[i].extmatch) / sizeof(lang[i].extmatch[0]); x++) {
        language = &lang[i];
        if (language->extmatch[x] == NULL)
          break;
        if (endswith(name, language->extmatch[i])) {
          language->count++;
          return language->name;
        }
      }
    }
  }
  return "";
}

void record()
{
  DIR *dir = opendir("./");
  struct dirent *ent;
  if (!dir) {
    perror("Unable to read current directory");
    exit(1);
  }

  while ((ent = readdir(dir)) != NULL) {
    switch (ent->d_type) {
      case DT_DIR: {
        matchlang(ent->d_name, 1);
        break;
      }
      case DT_LNK:
      case DT_REG: {
        matchlang(ent->d_name, 0);
        break;
      }
      default: break;
    }
  }
  closedir(dir);
}

struct Language gethighest()
{
  const int len = sizeof(lang) / sizeof(lang[0]);
  struct Language buf[len];
  struct Language bufa, bufb;

  for (int i = 0; i < len; i++)
    buf[i] = lang[i];

  for (int i = 0; i < len; i++) {
    for (int x = i + 1; x < len; x++) {
      if (buf[i].count < buf[x].count) {
        bufa = buf[i];
        buf[i] = buf[x];
        buf[x] = bufa;
      }
    }
  }

  return buf[0];
}

char* what()
{
  record();
  struct Language highest = gethighest();
  if (highest.count <= 0)
    exit(1);
  return highest.name;
}

int has() {
  record();
  struct Language highest = gethighest();
  if (highest.count <= 0)
    return 1;
  return !strcmp(highest.name, "");
}

int no() {
  record();
  struct Language highest = gethighest();
  if (highest.count <= 0)
    return 0;
  return strcmp(highest.name, "");
}

int main(int argc, char *argv[])
{
  if (!argv[1] || strequal(argv[1], "help")) {
    printf("Usage: %s [OPTION]\n\n", argv[0]);
    printf("  what            shows the most dominant language in current working directory\n");
    printf("  has             exits with 1 if no files found, otherwise 0\n");
    printf("  no              exits with 0 if no files found, otherwise 1\n");
  } else if (strequal(argv[1], "what")) {
    printf("%s\n", what());
  } else if (strequal(argv[1], "has")) {
    exit(has());
  } else if (strequal(argv[1], "no")) {
    exit(no());
  } else {
    printf("Usage: %s [OPTION]\n\n", argv[0]);
    printf("  what            shows the most dominant language in current working directory\n");
    printf("  has             exits with 1 if no files found, otherwise 0\n");
    printf("  no              exits with 0 if no files found, otherwise 1\n");
  }
}