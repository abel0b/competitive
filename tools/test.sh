workspace=$(pwd)

for year in *
do
    if [[ "$year" =~ ^[0-9]+$ ]]
    then
        for round in $year/*
        do
            for problem in $round/*
            do
                make -s -C "$workspace/$problem"
                make -s -C "$workspace/$problem" test
            done
        done
    fi
done