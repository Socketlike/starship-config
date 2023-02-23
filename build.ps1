if (($args[0] -eq "curved") -or ($args[0] -eq "powerline") -or ($args[0] -eq "sharp")) {
  if (!(Test-Item -Path .\build)) {
    New-Item -Path . -Name "build" -ItemType Directory
  }

  Copy-Item -Path .\starship\std.toml -Destination .\build
  $Content = (Get-Content -Path .\build\std.toml -Raw)

  if ($args[0] -eq "curved") {
    $Content = $Content -replace "{!CHAR_DIVIDER!}",""
  }
  elseif ($args[0] -eq "powerline") {
    $Content = $Content -replace "{!CHAR_DIVIDER!}",""
  }
  else if ($args[0] -eq "sharp") {
    $Content = $Content -replace "{!CHAR_DIVIDER!}",""
  }

  Set-Content -Path .\build\std.toml -Value "$Content"

  if (!(Test-Item -Path "$Env:USERPROFILE\starship")) {
    New-Item -Path $Env:USERPROFILE -Name "starship" -ItemType Directory
  }

  Copy-Item -Path .\build\std.toml -Destination "$Env:USERPROFILE\starship"

  echo "Done. Don't forget to set your STARSHIP_CONFIG variable to point to $Env:USERPROFILE\starship\std.toml."
}