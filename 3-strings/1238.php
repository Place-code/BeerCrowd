<?php
$REP=(int)readLine();
for($I=0;$I<$REP;++$I){
	list($STR1,$STR2)=explode(' ',readline());
	for($J=0;$J<max(strlen($STR1),strlen($STR2));++$J){
		if($J<strlen($STR1))
			echo $STR1[$J];
		if($J<strlen($STR2))
			echo $STR2[$J];
	}
	echo "\n";
}
?>
