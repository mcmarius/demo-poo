./artifacts/bin/demo-sfml &
sleep 3 && xdotool search --name "My Window" key X &&
sleep 1 && xdotool search --name "My Window" key Y &&
sleep 1 && xdotool search --name "My Window" key X &&
sleep 1 && xdotool search --name "My Window" key Z &&
sleep 2 && xdotool search --name "My Window" key Alt+F4
#DISPLAY=:99.0 ASAN_OPTIONS=halt_on_error=0 ./artifacts/bin/demo-sfml
#ASAN_OPTIONS=halt_on_error=0 ./artifacts/bin/demo-sfml
# wmctrl -lx
