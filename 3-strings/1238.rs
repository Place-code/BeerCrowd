use std::io;
use std::cmp;
//
fn main()->io::Result<()>{
    let mut temp=String::new();
    io::stdin().read_line(&mut temp)?;

    let rep:i32=match temp.trim().parse(){
        Ok(i)=>i,
        Err(..)=>0,
    };
    for _i in 0..rep{
        let mut strs=String::new();
        io::stdin().read_line(&mut strs)?;
        let array_str:Vec<&str>=strs.trim().split(' ').collect();

        let (str_1_len,str_2_len)=(array_str[0].len(),array_str[1].len());
        for _j in 0..cmp::max(str_1_len,str_2_len){
            if _j<str_1_len{
                print!("{}",array_str[0].chars().nth(_j).unwrap());
            }
            if _j<str_2_len{
                print!("{}",array_str[1].chars().nth(_j).unwrap());
            }
        }
        print!("\n");
    }
    
    Ok(())
}
