function test_problem {
    make -s -C "$1" test > /dev/null 2>&1
}

for year in *
do
    if [[ "$year" =~ ^[0-9]+$ ]]
    then
        for round in $year/*
        do
            for problem in $round/*
            do
                test_problem $problem
                if [[ "$?" == "0" ]]
                then
                    echo -ne "\e[32mPASS\e[0m"
                else
		            echo -ne "\e[31mFAIL\e[0m"
                fi
                echo -e "\e[0m $problem"
            done
        done
    fi
done
