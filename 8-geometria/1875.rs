use std::io;
//
const ASCII_R:u8="R".as_bytes()[0];
const ASCII_G:u8="G".as_bytes()[0];
const ASCII_B:u8="B".as_bytes()[0];

fn score(issuer:u8,receiver:u8)->u8{

    if issuer==ASCII_B && receiver==ASCII_R {
        return 2
    } else if issuer==ASCII_B {
        return 1;
    }

    if issuer==ASCII_G && receiver==ASCII_B{
        return 2;
    } else if issuer==ASCII_G{
        return 1;
    }

    if issuer==ASCII_R && receiver==ASCII_G{
        return 2;
    } else if issuer==ASCII_R{
        return 1;
    }

    0
}


fn main()->io::Result<()>{
    let mut input=String::new();
    io::stdin().read_line(&mut input)?;
    let rep:i16=input.trim().parse().expect("");

    for _i in 0..rep{
        input.clear();
        io::stdin().read_line(&mut input)?;
        let (goals,mut scores):(u16,[u32;3])=(input.trim().parse().expect(""),[0;3]);
        for _j in 0..goals{
            input.clear();
            io::stdin().read_line(&mut input)?;
            let teams:Vec<&str>=input.trim().split(" ").collect();
            let (str_1_chr,str_2_chr):(u8,u8)=(teams[0].as_bytes()[0],teams[1].as_bytes()[0]);

            if str_1_chr==ASCII_R {
                scores[0]+=score(str_1_chr,str_2_chr) as u32;
            }else if str_1_chr==ASCII_G {
                scores[1]+=score(str_1_chr,str_2_chr) as u32;
            }else if str_1_chr==ASCII_B {
                scores[2]+=score(str_1_chr,str_2_chr) as u32;
            }
        }
        if scores[0]>scores[1]&&scores[0]>scores[2]{
            println!("red");
        }else if scores[1]>scores[0]&&scores[1]>scores[2]{
            println!("green");
        }else if scores[2]>scores[0]&&scores[2]>scores[1]{
            println!("blue");
        }else if scores[0]==scores[1]&&scores[0]==scores[2]{
            println!("trempate");
        }else if scores[0]==scores[1]||scores[0]==scores[2]||scores[1]==scores[2]{
            println!("empate");
        }
    }

    Ok(())
}
