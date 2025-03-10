<?php
function spore($ISSUER,$RECEIVER):int{
	if($ISSUER==ord('R')&&$RECEIVER==ord('G'))
		return 2;
	else if($ISSUER==ord('R'))
		return 1;

	if($ISSUER==ord('G')&&$RECEIVER==ord('B'))
		return 2;
	else if($ISSUER==ord('G'))
		return 1;

	if($ISSUER==ord('B')&&$RECEIVER==ord('R'))
		return 2;
	else
		return 1;
}


$REP=(int)readline();
for($I=0;$I<$REP;++$I){
	$GOALS=(int)readline();
	$ARR=array(0,0,0);
	for($J=0;$J<$GOALS;++$J){
		$STR=readline();
		$TOKEN=strtok($STR," ");

		$STR_1_CHR=ord($TOKEN[0]);
		$TOKEN=strtok(" ");
		$STR_2_CHR=ord($TOKEN[0]);

		if($STR_1_CHR==ord('B'))
			$ARR[0]+=spore($STR_1_CHR,$STR_2_CHR);
		if($STR_1_CHR==ord('G'))
			$ARR[1]+=spore($STR_1_CHR,$STR_2_CHR);
		if($STR_1_CHR==ord('R'))
			$ARR[2]+=spore($STR_1_CHR,$STR_2_CHR);
	}
	if($ARR[0]>$ARR[1]&&$ARR[0]>$ARR[2])
		echo "blue\n";
	else if($ARR[1]>$ARR[0]&&$ARR[1]>$ARR[2])
		echo "green\n";
	else if($ARR[2]>$ARR[0]&&$ARR[2]>$ARR[1])
		echo "red\n";
	else if($ARR[0]==$ARR[1]&&$ARR[1]==$ARR[2])
		echo "trempate\n";
	else if($ARR[0]==$ARR[1]||$ARR[0]==$ARR[2]||$ARR[1]==$ARR[2])
		echo "empate\n";
}
?>
