sleep 2 && xdotool search --name "My Window" key X &
sleep 2 && xdotool search --name "My Window" key Y &
sleep 2 && xdotool search --name "My Window" key X &
sleep 2 && xdotool search --name "My Window" key Z &
sleep 24 && xdotool search --name "My Window" key Alt+F4 &
valgrind --leak-check=full --error-exitcode=0 ./artifacts/bin/demo-sfml

