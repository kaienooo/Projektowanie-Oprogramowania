$sourceFiles = @(
    "libssl-3-x64.dll",
    "libcrypto-3-x64.dll"
)

# Destination path relative to the script's directory
$destination = "..\Build\x64\Release\bin\"

# Resolve the full path to the destination
$scriptDirectory = Split-Path -Parent -Path $MyInvocation.MyCommand.Definition
$destinationFullPath = Join-Path -Path $scriptDirectory -ChildPath $destination

# Check if the destination directory exists, create it if it doesn't
if (-not (Test-Path -Path $destinationFullPath)) {
    Write-Host "Destination directory does not exist. Creating: $destinationFullPath" -ForegroundColor Yellow
    New-Item -ItemType Directory -Path $destinationFullPath | Out-Null
}

# Move each file
foreach ($file in $sourceFiles) {
    $sourceFullPath = Join-Path -Path $scriptDirectory -ChildPath $file
    if (Test-Path -Path $sourceFullPath) {
        Write-Host "Moving $file to $destinationFullPath" -ForegroundColor Green
        Copy-Item -Path $sourceFullPath -Destination $destinationFullPath -Force
    } else {
        Write-Host "File not found: $file" -ForegroundColor Red
    }
}