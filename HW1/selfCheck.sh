
#!/bin/bash
# change these per each homework
#	link to tests:
testsurl="https://webcourse.cs.technion.ac.il/fc159753hw_236360_202002/hw/WCFiles/hw1-tests.zip"

hostname="cscomp"
tmpdir="selfcheck_tmp"

if [ $( hostname ) != "$hostname" ]
	then
		echo "This script is only intended to run on $hostname"
		exit
fi

if [ -z "$1" ]
	then
		echo "Usage: ./"$( basename "$0" )" <your submission="" zip="" file="">"
		exit
fi

if [ ! -f "$1" ]
	then
		echo "Submission zip file not found!"
		exit
fi

rm -rf "$tmpdir" &amp;&gt; /dev/null
if [ -d "$tmpdir" ]
	then
		echo "Cannot clear tmp directory. Please delete '"$tmpdir"' manually and try again"
		exit
fi
mkdir "$tmpdir" &amp;&gt; /dev/null

unzip "$1" -d "$tmpdir" &amp;&gt; /dev/null
if [[ $? != 0 ]] 
	then
		echo "Unable to unzip submission file!"
		exit
fi

cd "$tmpdir"
if [ ! -f scanner.lex ]
	then
		echo "File hw1.lex not found!"
		exit
fi

flex scanner.lex &amp;&gt; /dev/null
if [[ $? != 0 ]] 
	then
		echo "Cannot build submission!"
		exit
fi
g++ -std=c++11 lex.yy.c part_a.cpp -o part_a.out &amp;&gt; /dev/null
if [[ $? != 0 ]] 
	then
		echo "Cannot build submission!"
		exit
fi
if [ ! -f part_a.out ]
	then
		echo "Cannot build submission!"
		exit
fi
g++ -std=c++11 lex.yy.c part_b.cpp -o part_b.out &amp;&gt; /dev/null
if [[ $? != 0 ]] 
	then
		echo "Cannot build submission!"
		exit
fi
if [ ! -f part_b.out ]
	then
		echo "Cannot build submission!"
		exit
fi
wget  --no-check-certificate "$testsurl" &amp;&gt; /dev/null
if [ ! -f $( basename "$testsurl" ) ]
	then
		echo "Unable to download tests!"
		exit
fi

unzip $( basename "$testsurl" ) &amp;&gt; /dev/null
if [[ $? != 0 ]] 
	then
		echo "Unable to unzip tests!"
		exit
fi

#	number of tests:
numtests=2
#	command to execute test:
command="./part_a.out &lt; ta\$i.in &gt;&amp; ta\$i.res"
i="1"
while [ $i -le $numtests ]
	do
		eval $command
		diff ta$i.res ta$i.out &amp;&gt; /dev/null
		if [[ $? != 0 ]] 
			then
				echo "Failed test #"$i"!"
				exit
		fi
		i=$[$i+1]
done

#	number of tests:
numtests=2
#	command to execute test:
command="./part_b.out &lt; tb\$i.in &gt;&amp; tb\$i.res"
i="1"
while [ $i -le $numtests ]
	do
		eval $command
		diff tb$i.res tb$i.out &amp;&gt; /dev/null
		if [[ $? != 0 ]] 
			then
				echo "Failed test #"$i"!"
				exit
		fi
		i=$[$i+1]
done

cd - &amp;&gt; /dev/null
rm -rf "$tmpdir"

echo "Ok to submit :)"
exit
