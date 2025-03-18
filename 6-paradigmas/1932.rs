use std::io;

fn main()->io::Result<()>{
    let mut inp=String::new();
    io::stdin().read_line(&mut inp)?;
    let mut parts:Vec<&str>=inp.trim().split(" ").collect();
    let price=parts[1].parse::<i32>().unwrap();
    parts.clear();

    let mut inp2=String::new();
    io::stdin().read_line(&mut inp2)?;
    parts=inp2.trim().split(" ").collect();
    let (mut right,mut left,mut tot,mut tot_temp):(i32,i32,i32,i32)=(0,0,0,0);
    left=parts[0].parse::<i32>().unwrap();
    for i in 1..parts.len(){
        right=parts[i].parse::<i32>().unwrap();
        if right-left>=tot_temp {
            tot_temp=if(right-left-price>tot_temp){ right-left-price}else{tot_temp};
        }else if tot_temp !=0 {
            tot+=tot_temp;
            tot_temp=0;
            left=right;
        }else{
            left=if(right<left){right}else{left};
        }
    }
    tot+=tot_temp;
    println!("{}",tot);

    Ok(())
}
