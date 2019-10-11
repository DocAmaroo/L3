#!/bin/bash

# CONSTANT COLOR
RED='\033[0;31m'
ORANGE='\033[0;33'
NC='\033[0m' # No Color

git add *

printf '${ORANGE}\n## REMOVING FILES FROM "add *" ## \n'
printf '#################################\n${NC}'
git rm --cached S5/HLIN501_algo_de_graphes/cours.pdf

printf '${ORANGE}\n## STATUS ##\n'
printf '############\n${NC}'
git status

printf '${ORANGE}## COMMIT MESSAGE ##\n'
printf '####################\n${NC}' 
read commitMessage

git commit -am "$commitMessage"

git push
