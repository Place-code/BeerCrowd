<?php
class Car{
	public $PLATE,$START,$END;

	function __construct($ID,$INIT,$END){
		$this->PLATE=$ID;
		$this->START=$INIT;
		$this->END=$END;
	}
	function display(){
		print($this->PLATE." ".$this->START." ".$this->END."|");
	}
}

class Node{
	public $next,$PREV,$VALUE;

	function __construct($CAR_VALUE,$PREV_VALUE){
		$this->value=$CAR_VALUE;
		$this->next=null;
		$this->prev=$PREV_VALUE;
	}
}
class Head_ll{
	public $head,$first,$last;

	function __construct(){
		$this->head=new Node(null,null);
		$this->first=$this->head;
		$this->last=$this->head;
	}
	function insert($new_value){
		if($this->head->value==null){
			$this->last=$this->head;

			$this->head->value=$new_value;
			$this->head->next=new Node(null,$this->head);
			$this->head=$this->head->next;
			return;
		}
		if($this->head->prev==null){
			$this->head->prev=new Node($new_value,null);
			$this->head->prev->next=$this->head;
			$this->head=$this->head->prev;
			$this->first=$this->head;
			return;
		}
		$temp=$this->head;
		$this->head=$this->head->prev;
		$this->head->next=new Node($new_value,$this->head);
		$this->head=$this->head->next;
		$this->head->next=$temp;
		$temp->prev=$this->head;
	}
	function delete(){
		if($this->head->prev==null){
			$this->head->value=null;
			if($this->head->next!=null&&$this->head->next->value!=null){
				$this->head=$this->head->next;
				$this->head->prev=null;
			}
			$this->first=$this->head;
			return;
		}
		if($this->head->value==null){
			$this->head=$this->head->prev;
			$this->head->next=null;
			$this->head->value=null;
			$this->last=$this->head->prev;
			return;
		}
		$temp=$this->head->next;
		$this->head=$this->head->prev;
		$this->head->next=$temp;
		$temp->prev=$this->head;
		if($temp->next==null||$temp->next->value!=null)
			$this->last=$temp->prev;
	}
	function move_start(){
		$this->head=$this->first;
	}
	function move_end(){
		$this->head=$this->last;
	}

	function display_start(){
		$temp=$this->first;
		while($temp->value!=null){
			$temp->value->display();
			$temp=$temp->next;
		}
		print("\n");
	}
	function display_end(){
		$temp=$this->last;
		while($temp!=null&&$temp->value!=null){
			$temp->value->display();
			$temp=$temp->prev;
		}
		print("\n");
	}
	function is_empty(){
		return ($this->first==$this->last&&$this->first->value==null);
	}
}

function let_parking($park,$ID){
	$park->move_start();
	while($park->head->value!=null){
		if($park->head->value->PLATE==$ID){
			$park->delete();
			return;
		}
		$park->head=$park->head->next;
	}
}
function inp_parking($park,$len_park,$ID_car,$len_car){
	$park->move_start();
	if($len_car>$len_park)
		return 0;
	if($park->head->value==null||$park->head->value->START>=$len_car){
		$park->insert(new Car($ID_car,0,$len_car-1));
		return 1;
	}
	$prev_end=$park->head->value->END;
	$park->head=$park->head->next;
	while($park->head->value!=null){
		$curr=$park->head->value;
		if($curr->START-$prev_end>$len_car){
			$park->insert(new Car($ID_car,$prev_end+1,$prev_end+$len_car));
			return 1;
		}
		$prev_end=$curr->END;
		$park->head=$park->head->next;
	}
	if($len_park-$prev_end>$len_car){
		$park->insert(new Car($ID_car,$prev_end+1,$prev_end+$len_car));
		return 1;
	}
	return 0;
}

/*
$TST=new Head_ll();
for($I=0;$I<10;++$I){
	$STR=chr($I%25+65).chr(($I+1)%26+65).chr(($I+2)%26+65);
	$TST->insert(new Car($STR,$I,$I));
}

$TST->move_end();
while(!$TST->is_empty()){
	$TST->head->value->display();
	$TST->delete();
}
echo "\n";
 */

while(($line=readLine())!==false){
	list($length,$quotes)=explode(' ',$line);
	$length=(int)$length;
	$quotes=(int)$quotes;
	$dict=array();
	$parking=new Head_ll();
	$tot=0;
	while($quotes>0){
		$str=explode(' ',readLine());

		if(sizeof($str)<3&&array_key_exists($str[1],$dict)){
			let_parking($parking,$str[1]);
			unset($dict[$str[1]]);
		}else if(sizeof($str)==3&&inp_parking($parking,$length,$str[1],(int)$str[2])){
			$dict[$str[1]]=true;
			$tot+=10;
		}
		//$parking->display_start();

		--$quotes;
	}
	print($tot);
	print("\n");
}
?>
