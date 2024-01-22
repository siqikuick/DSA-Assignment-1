$programs = @("cmake", "make")

$program_not_installed = 0

foreach ($program in $programs) {
    if (!(Test-Path "($program)".exe)) {
        Write-Error "Error: $program is not installed."
        $program_not_installed = 1
    }
}

if ($program_not_installed -eq 1) {
    exit 1
}

Write-Host "Building the project..."

New-Item -Path "build" -ItemType Directory -Force
Set-Location "build"

cmake ..
make

Write-Host "Done!"