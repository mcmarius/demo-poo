sleep 2 && xdotool search --name "My Window" key X &
sleep 2 && xdotool search --name "My Window" key Y &
sleep 2 && xdotool search --name "My Window" key X &
sleep 2 && xdotool search --name "My Window" key Z &
valgrind --leak-check=full --error-exitcode=0 ./artifacts/bin/demo-sfml
# sleep 4 && xdotool search --name "My Window" windowactivate --sync %1 key Alt+F4
