# TB VS Bass 100 (2026 Mac)

A model of the **H/H VS Bass 100** bass amplifier as **CLAP, VST3 and AU** plugins for current
Macs: universal (Apple Silicon + Intel), macOS 11 and later, for Reaper, FL Studio, Logic and
other hosts. Non-commercial, personal use.

This is the same circuit model, panel and presets as the Mountain Lion VST
([TB-HH-Bass-MOUNTAIN-LION](https://github.com/tonybuzzcock/TB-HH-Bass-MOUNTAIN-LION)); the test
suite checks the output matches it sample for sample. See that repo's README for what is
modelled from the *V-S Bassamp Circuit Diagram* C/AC00015 (in `Docs/`) and which values are
estimates, including the cab low-end voicing.

## The panel

| Control band | **Gain**, **Bass Boost** (Off/On rotary), **Bass, Middle, Treble, Presence** (−5 · 0 · +5), **Valve Sound** (Off/On rotary), **Master Volume** |
|---|---|
| Name strip | TB electronic logo, model name, red **Mains** rocker |
| Plugin strip | **Cab** (1x15 / 4x10), **Speaker** (miked cab or speaker terminals), **Input** ±12 dB, **Output** ±24 dB, 8 named presets, readout |

Every switch lights up on its engaged side. **Mains** off passes the dry signal, time-aligned.

## Download and install

1. Repo → **Actions** → newest green run → Artifacts → **TB-HH-Bass-mac** → download and unzip
   (twice: the artifact zip holds `TB-HH-Bass-mac.zip`).
2. Follow **INSTALL.txt** inside: copy the plugins into `/Library/Audio/Plug-Ins/` (VST3, Components,
   CLAP), then in Terminal, one line at a time:

        cd /Library/Audio/Plug-Ins
        ls */ | grep -i "vs bass"
        sudo xattr -cr */"TB VS Bass 100".*
        sudo codesign --force --deep --sign - */"TB VS Bass 100".*
        killall -9 AudioComponentRegistrar

3. In Reaper: Settings > Plug-ins > VST and CLAP > **Clear cache/re-scan**.

## Build

    cmake -B build -DCMAKE_BUILD_TYPE=Release
    cmake --build build -j4

clap-wrapper (v0.17.0) and the CLAP, VST3 and AudioUnit SDKs are fetched at configure time.
On Linux this builds the CLAP and the tests (`preset_test`, `vsbass_test`, `clap_host_test`).
GitHub Actions builds all three formats, checks they are universal with a minimum of macOS 11,
runs the tests, the panel test, auval, clap-validator and pluginval, and publishes panel
screenshots to the `gui-preview` branch.
