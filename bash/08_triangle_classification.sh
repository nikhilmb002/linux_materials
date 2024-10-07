# if all 3 sides are equal, output EQUILATERAL, otherwise 
# if any 2 sides are equal, output ISOSCELES
# otherwise, output SCALANE

read x
read y
read z

if [[ "$x" == "$y" && "$y" == "$z" ]]; then
	echo "EQUILATERAL"

elif [[ "$x" == "$y" || "$x" == "$z" || "$y" == "$z" ]]; then
	echo "ISOSCELES"

else 
	echo "SCALANE"

fi
