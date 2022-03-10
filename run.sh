# sleep 2 && xdotool search --name "My Window" key X &
env
DISPLAY=:99.0
ASAN_OPTIONS=halt_on_error=0
env
DISPLAY=:99.0 ASAN_OPTIONS=halt_on_error=0 sleep 1 && xdotool search --name "My Window" key X &
DISPLAY=:99.0 ASAN_OPTIONS=halt_on_error=0 ./artifacts/bin/demo-sfml &
# wmctrl -lx