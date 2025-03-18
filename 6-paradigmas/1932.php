<?php
list($quotes,$price)=explode(' ',readLine());
$price=(int)$price;

$left=10001;
$tot_temp=0;
$tot=0;
foreach(explode(' ',readLine()) as $right){
	if($right-$left>=$tot_temp){
		$tot_temp=($right-$left-$price>$tot_temp)?$right-$left-$price:$tot_temp;
	}else if($tot_temp){
		$tot+=$tot_temp;
		$tot_temp=0;
		$left=$right;
	}else{
		$left=($right<$left)?$right:$left;
	}
}
$tot+=$tot_temp;
print $tot;
print "\n";

?>
