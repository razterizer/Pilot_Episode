# Release Notes

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
