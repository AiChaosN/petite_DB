if [ $1 = "push" ]; then
    git add .
    git commit -m "$1"
    git push
fi

if [ $1 = "pull" ]; then
    git pull
fi