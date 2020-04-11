if [[ $# != 2 ]]
then
    echo "Usage: $0 <round> <problem>"
    exit 1
fi

year=$(date +%Y)
mkdir -p $year
mkdir -p $year/$1
cp -r template $year/$1/$2
