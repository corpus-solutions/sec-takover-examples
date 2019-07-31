#!/bin/bash

# Open the FakeUpdate page with Safari 
TARGET_URL="http://fakeupdate.net/apple/"
open -a Safari $TARGET_URL

# Switch Safari to Full-screen (this is already secured using Privacy) using AppleScript
/usr/bin/osascript \
-e 'tell application "Safari"' \
-e "activate" \
-e 'tell application "System Events"' \
-e 'keystroke "f" using {control down, command down}' \
-e "end tell" \
-e "end tell"

# TODO: Tap the right button using Mouse HID
