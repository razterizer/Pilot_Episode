# Release Notes

## 1.3.4.10

- Bumping dependencies.

## 1.3.3.9

- Using applaudio version with windows library dependency "ksguid".

## 1.3.2.8

- Switch the Forge-hosted 8Beat dependency to the explicit applaudio cbox variant.

## 1.3.1.7
- Adopted Forge release workflow packaging with direct Termin8or and 8Beat dependencies.
- Verifies Core is resolved transitively through both dependency paths.
- Uses Termin8or 3.0.3.9 exported font runtime assets staged as `Termin8or/fonts`.

## 1.3.0.6
- Bumped Termin8or dependency to 3.0.0.6.
- Updated compatibility with Termin8or's Unicode/glyph API changes.

## 1.2.0.5
- Using Termin8or 2.0.0.2 with 8-bit color support.

## 1.1.2.4
- Fixes the --help argument so that it doesn't display audio settings on top of the help text, which seems a little out of place.
- Using AudioSource objects instead of AudioStreamSource objects as AudioStreamSources were originally designed for streaming via listener interface.
- Adding CLArgs --music_volume and --sfx_volume and improving help page formatting.
- Only bumping patch number here though it should be a bumped minor number because of accidental (doubtfully correct) bumping of minor number back in 1.1.0.2.

## 1.1.1.3
- Added unblocking instructions in readme for macos and windows and added additional chmodding instructions in readme for linux.

## 1.1.0.2
- Trying building two different binaries for linux. One which uses glibc2.38 (e.g. ubuntu latest), and another one that uses glibc2.35 (e.g. ubuntu wsl).

## 1.0.1.1
- Fixed partial redraw for linux and wsl. So now the rendering should l…

## 1.0.0.0
- Added release workflows to xcode project.
