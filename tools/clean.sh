workspace=$(pwd)

for year in *
do
    if [[ "$year" =~ ^[0-9]+$ ]]
    then
        for round in $year/*
        do
            for problem in $round/*
            do
                make -C "$workspace/$problem" clean
            done
        done
    fi
done