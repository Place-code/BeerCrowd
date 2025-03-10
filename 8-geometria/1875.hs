import Data.Char (ord)
import Data.Array 

scores::Int->Int->Int
scores issuer receiver
 |issuer==ord('R')&&receiver==ord('G')=2
 |issuer==ord('R')=1
 |issuer==ord('G')&&receiver==ord('B')=2
 |issuer==ord('G')=1
 |issuer==ord('B')&&receiver==ord('R')=2
 |otherwise=1

question::String->Array Int Int->Array Int Int 
question str arr=do
	let inp=words str
	let	first_chr=ord((inp!!0)!!0)
	let	second_chr=ord((inp!!1)!!0)
	let	goals=scores first_chr second_chr

	if first_chr==ord('R')then arr//[(0,((arr!0)+goals))]
	else if first_chr==ord('G')then arr//[(1,(arr!1)+goals)]
	else arr//[(2,(arr!2)+goals)]

answer::Array Int Int->IO(String)
answer goals=do
	if goals!0>goals!1&&goals!0>goals!2 then return "red"
	else if goals!1>goals!0&&goals!1>goals!2 then return "green"
	else if goals!2>goals!0&&goals!2>goals!1 then return "blue"
	else if goals!0==goals!1&&goals!1==goals!2 then return "trempate"
	else return  "empate"

main::IO()
main=do
	n<-readLn::IO Int
	loop_i n

loop_i::Int->IO()
loop_i 0=return ()
loop_i i=do
	m<-readLn::IO Int
	let temp=array(0,2)[(0,0),(1,0),(2,0)]
	goals<-loop_j m temp
	awns<-answer goals
	putStrLn awns
	loop_i (i-1)

loop_j::Int->Array Int Int->IO(Array Int Int)
loop_j 0 arr = return arr
loop_j j arr=do
	temp<-getLine
	let new_arr=question temp arr
	loop_j (j-1) new_arr
