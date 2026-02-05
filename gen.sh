MAX=256

for ((n = 0; n <= MAX; n++)); do
	args=""
	for ((i=0; i<=n; i++)); do
		if [[ $i -eq 0 ]]; then
			args="a0"
		else
			args="$args,a$i"
		fi
	done

	echo "# define _M_TUPLE_ELEM_${n}(${args},...) a${n}"
done