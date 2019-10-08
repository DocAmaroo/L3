#!/bin/bash

git add *

printf '\n## REMOVING FILES FROM "add *" ## \n'
printf '#################################\n'
git rm --cached S5/HLIN501_algo_de_graphes/cours.pdf

printf '\n## STATUS ##\n'
printf '############\n'
git status

printf '## COMMIT MESSAGE ##\n'
printf '####################\n' 
read commitMessage

git commit -am "$commitMessage"

git push
