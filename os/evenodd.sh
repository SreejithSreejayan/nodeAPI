clear 
echo "    even or odd in shell script   "
echo "Enter a number:"
read n
echo "RESULT:"
if [ `expr $n % 2` == 0 ]
then	
	echo "$n is even"
else	
	 echo "$n is odd"
fi

