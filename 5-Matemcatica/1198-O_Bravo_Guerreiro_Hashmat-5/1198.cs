using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        while(true){
            try{
                string[] nums = Console.ReadLine().Split(' ');
                long result= long.Parse(nums[1]) - long.Parse(nums[0]);
                if (result < 0){result*=-1;}
                Console.WriteLine(result);
            }
            catch(Exception ex){
                break;
            }
        }
    }
}