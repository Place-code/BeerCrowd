use std::io;
use std::option;

#[derive(Clone)]
struct Car{
    ID:String,
    init:u16,
    end:u16,
}

impl Car{
    pub fn new(identity:String,start:u16,end:u16)->Self{
        Car{ID:identity,init:start,end:end}
    }
    pub fn display_car(&self){
        print!("{} {} {}|",self.ID,self.init,self.end);
    }
}

#[derive(Clone)]
struct Node{
    value:Option<Car>,
    prev:Option<Box<Node>>,
    next:Option<Box<Node>>,
}
impl Node{
    pub fn new(new_car:Option<Car>,prev:Option<Box<Node>>)->Option<Box<Self>>{
        if !prev.is_none(){
            return Some(Box::new(Node{value:new_car,prev:prev,next:None}));
        }
        return Some(Box::new(Node{value:new_car,prev:None,next:None}));
    }
    pub fn get_value(&self)->Option<Car>{
        self.value.clone()
    }
    pub fn change_value(&mut self,new_value:Option<Car>){
        self.value=new_value;
    }
    pub fn display_node(&self){
        if let Some(value)=&self.value{
            value.display_car();
        }
    }
}

struct Head_ll{
    head:Option<Box<Node>>,
    last:Option<Box<Node>>,
    prim:Option<Box<Node>>,
}
impl Head_ll{
    pub fn new()->Self{
        let mut new=Head_ll{head:Node::new(None,None),prim:None,last:None};
        new.prim=new.head.clone();
        new.last=new.head.clone();
        new
    }
    pub fn move_forward(&mut self){
        if let Some(mut forward)=self.head.take(){
            self.head=forward.next.take();
        }
    }
    pub fn get_clone(target:&mut Option<Box<Node>>)->&mut Box<Node>{
        let Some(ref mut res)=target else { todo!() };
        res
    }
    pub fn insert(&mut self,new_car:Car){
        let unpack=Head_ll::get_clone(&mut self.head);
        match unpack.get_value(){
            Some(_)=>{
                println!("There!");
            }None=>{
                unpack.change_value(Some(new_car));
                unpack.next=Node::new(None,Some(unpack.clone()));
                self.last=self.head.clone();
                self.move_forward();
                return;
            }
        }
        match unpack.prev{
            Some(_)=>{}
            None=>{
                println!("NAO");
            }
        }
    }
    pub fn move_start(&mut self){
        self.head=self.prim.clone();
    }
    pub fn move_end(&mut self){
        self.head=self.last.clone();
    }

    pub fn display_start(&self){
        let mut temp=self.prim.as_ref();
        while let Some(current)=temp{
            current.display_node();
            temp=current.next.as_ref();
        }
        print!("\n");
    }
    pub fn display_end(&self){
        let mut temp=self.last.as_ref();
        while let Some(current)=temp{
            current.display_node();
            temp=current.prev.as_ref();
        }
        print!("\n");
    }
}

fn main(){
    let mut tst:Head_ll=Head_ll::new();
    tst.insert(Car::new("1234".to_string(),0,0));
    tst.insert(Car::new("1235".to_string(),0,0));
    tst.display_end();
    tst.display_start();
}
