import Data.Array

max_str::String->String->Int
max_str str_1 str_2
 |(length str_1)>(length str_2)=(length str_1)
 |otherwise=(length str_2)

display_chr::String->Int->Int->IO()
display_chr str max_len current_itr
 |current_itr>max_len-1=return()
 |otherwise=putChar (str!!current_itr)

main::IO()
main=do
	n<-readLn::IO Int
	loop_i n

loop_i::Int->IO()
loop_i 0=return ()
loop_i i=do
	str<-getLine
	let str_splited=words str
	let max_length_str=max_str (str_splited!!0) (str_splited!!1)
	one_by_one str_splited max_length_str 0
	putChar '\n'
	loop_i (i-1)

one_by_one::[String]->Int->Int->IO()
one_by_one str_list max_length j
 |j>max_length=return()
 |otherwise=do
	display_chr (str_list!!0) (length (str_list!!0)) j
	display_chr (str_list!!1) (length (str_list!!1)) j
	one_by_one str_list max_length (j+1)
