printf "\e[32m"
make
while true; do
    printf "\e[32mValgrind philo_two (Vv), Cat full report (Cc), Infinite mode (Ii), Make re (Mm), Exit (Ee) : "
	read -p "" choice
    case $choice in
        [Vv]* )
			printf "\e[94m"
			valgrind --leak-check=full \
			 --show-leak-kinds=all \
			--child-silent-after-fork=yes \
			 --track-origins=yes \
			 --verbose \
			 --log-file=valgrind-out.txt ./philo_two
			printf "\e[91m"
			printf "VALGRIND OUTPUT\n"
			leak=`grep -A 5 "LEAK SUMMARY" valgrind-out.txt | grep -Po '^.{10}\K.*'`
			printf "\e[91m$leak"
			no_leak=`grep "All heap blocks were freed -- no leaks are possible" valgrind-out.txt | grep -Po '^.{8}\K.*'`
			printf "\e[91m$no_leak"
			printf "\n"
			error=`grep "ERROR SUMMARY" valgrind-out.txt | grep -Po '.{8}\K.*'`
			printf "\e[91m$error\n";;
        [Ii]* )
			while true; do
				printf "\e[94m"
				valgrind --leak-check=full \
				 --show-leak-kinds=all \
				--child-silent-after-fork=yes \
				--track-origins=yes \
				 --verbose \
				 --log-file=valgrind-out.txt ./philo_two
				printf "\e[91m------------VALGRIND OUTPUT\n"
				leak=`grep -A 5 "LEAK SUMMARY" valgrind-out.txt | grep -Po '^.{10}\K.*'`
				printf "\e[91m$leak"
				no_leak=`grep "All heap blocks were freed -- no leaks are possible" valgrind-out.txt | grep -Po '^.{8}\K.*'`
				printf "\e[91m$no_leak"
				printf "\n"
				error=`grep "ERROR SUMMARY" valgrind-out.txt | grep -Po '.{8}\K.*'`
				printf "\e[91m$error\n"
			done;;
        [Cc]* )
			printf "\e[37m" && cat valgrind-out.txt;;
        [Mm]* )
			printf "\e[32m" && make re;;
        [Ee]* )
			exit;;
        * )
			printf "\e[32mpakompri" && printf "\n";;
    esac
done
