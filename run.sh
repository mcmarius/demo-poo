./artifacts/bin/demo-sfml &
sleep 4 && xdotool search --name "My Window" windowactivate --sync %1 key Alt+F4
