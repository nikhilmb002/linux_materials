# if the character is 'Y' or 'y' display "YES"
# if the character is 'N' or 'n' display "NO"

read -n 1 ch

if [[ "$ch" == "Y" || "$ch" == "y" ]]; then
	echo "YES"

elif [[ "$ch" == "N" || "$ch" == "n" ]]; then
	echo "NO"

fi
