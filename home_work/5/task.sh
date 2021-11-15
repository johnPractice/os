#! /bin/bash

DB="./tasks.txt"
NUM_TASKS=0

add_task() {
	local TASK=$@ # new party (important)
	local P=""
	local LOWERCASE=$(echo $TASK | tr '[:upper:]' '[:lower:]')

	if [[ $LOWERCASE = *"(important)"* ]]; then
		P="M"
	elif [[ $LOWERCASE = *"(very important)"* ]]; then
		P="H"
	else
		P="L"
	fi

	local NEW_TASK=$P" "$TASK
	echo $NEW_TASK >>$DB
	NUM_TASKS=$(($NUM_TASKS + 1))
	echo "Added task $NUM_TASKS with priority $P"
}

list() {
	if [[ $NUM_TASKS == 0 ]]; then
		echo "No tasks found..."
	fi

	local I=1
	while read LINE; do
		#L new party"
		local TITLE=$(echo $LINE | cut -d " " -f2-)
		local P=$(echo $LINE | cut -d " " -f1)
		local STAR=""

		if [ "$P" == "L" ]; then
			STAR="*    "
		elif [ "$P" == "M" ]; then
			STAR="***  "
		else
			STAR="*****"
		fi
		echo "$I $STAR $TITLE"
		((I++))
	done <$DB
}

done_task() {
	# done_task 3
	local IDX=$1
	local TASK=$(sed -n "${IDX}p" $DB | cut -d " " -f2-)
	sed -i "${IDX}d" $DB
	echo "Completed task $IDX: $TASK"
}

init_task() {
	if [ ! -e $DB ]; then
		touch $DB
	fi

	NUM_TASKS=$(wc -l $DB | cut -d " " -f1)
}

init_task
COMMAND=$1

case $COMMAND in
"add")
	if [ "$2" == "" ]; then
		echo >&2 "[Error] This command needs an argument"
		exit 1
	fi
	add_task "$(echo $@ | cut -d " " -f2-)"
	;;
"list")
	list
	;;
"done")
	if [ "$2" == "" ]; then
		echo >&2 "[Error] This command needs an argument"
		exit 1
	fi
	done_task $2
	;;
*)
	echo >&2 "[Error] Invalid command"
	exit 1
	;;
esac
