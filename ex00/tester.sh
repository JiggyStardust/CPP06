#char test

echo "\n----------------------------"
echo 1. TEST WITH CHAR
echo ----------------------------

echo "\n1. a\n"
./convert a

echo "\n2.	\n"
./convert '	'

echo "\n3. !\n"
./convert !

echo "\n4. G\n"
./convert G


#int test

echo "\n----------------------------"
echo 2. TEST WITH INT
echo ----------------------------

echo "\n1. 0\n"
./convert 0

echo "\n2. 48\n"
./convert 48

echo "\n3. -3566\n"
./convert '-3566'

echo "\n4. 3025982309823098\n"
./convert 3025982309823098


#float test

echo "\n----------------------------"
echo 3. TEST WITH FLOAT
echo ----------------------------

echo "\n1. 0.0f\n"
./convert 0.0f

echo "\n2. -48.236f\n"
./convert 48.236f

echo "\n3. -3566.3252f\n"
./convert '-3566.3252f'

echo "\n4. 60000000000000000000000000000000000000.0f\n"
./convert 60000000000000000000000000000000000000.0f

echo "\n5. 600000000000000000000000000000000000000.0f\n"
./convert 600000000000000000000000000000000000000.0f


#double test

echo "\n----------------------------"
echo 4. TEST WITH DOUBLE
echo ----------------------------

echo "\n1. 0.0\n"
./convert 0.0

echo "\n2. -48.236\n"
./convert 48.236

echo "\n3. -3566.3252\n"
./convert '-3566.3252'

echo "\n4. 60000000000000000000000000000000000000.0\n"
./convert 60000000000000000000000000000000000000.0

echo "\n5. 600000000000000000000000000000000000000.0\n"
./convert 600000000000000000000000000000000000000.0


#pseudo literals test

echo "\n----------------------------"
echo 4. TEST WITH INF, INFF, NAN...
echo ----------------------------

echo "\n1. nan\n"
./convert nan

echo "\n2. nanf\n"
./convert nanf

echo "\n3. -nanf\n"
./convert '-nanf'

echo "\n4. +inff\n"
./convert +inff

echo "\n5. -inff\n"
./convert '-inff'

echo "\n6. +inf\n"
./convert +inf

echo "\n7. -inf\n"
./convert '-inf'

echo "\n8. joujou"
./convert joujou