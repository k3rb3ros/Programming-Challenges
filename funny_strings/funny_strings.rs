use std::io;

//n_str consist of a line containting a number n followed by n strings each on a new line
fn read_input() -> Vec<String>
{
    let mut n_str = String::new();
    let mut input : Vec<String> = vec![]; 
   
    io::stdin()
    .read_line(&mut n_str)
    .expect("failed to read n_str.");

    let inp_size : i16 = n_str.trim().parse::<i16>().expect("non integer input");

    for _ in 0..inp_size
    {
        let mut inp_line = String::new();
        io::stdin()
        .read_line(&mut inp_line)
        .expect("failed to read n_str.");

        input.push(String::from(inp_line.trim()));
    }

    return input;
}

//A funny string is an ascii string such that when the ascii value every characters is subtracted from the ascii value of the previous character and the absolute value is taken the same pattern is true for the reverse string.
fn str_is_funny(s: &String) -> bool
{
    let mut success: bool = false;
    //reverse the string and save it as a string
    let r : String = s.chars().rev().collect::<String>();

    //iterate through i to N-1
    for i in 0..s.len()-1
    {
        let s_n : i16 = s[i..i+1].as_bytes()[0] as i16;
        let s_np1 : i16 = s[i+1..i+2].as_bytes()[0] as i16;
        let r_n : i16 = r[i..i+1].as_bytes()[0] as i16;
        let r_np1 : i16 = r[i+1..i+2].as_bytes()[0] as i16;

        //println!("S_N {}, S_N+1 {} R_N {} R_N+1 {}", s_n, s_np1, r_n, r_np1);
            
        if ((s_np1-s_n).abs() == (r_np1-r_n).abs())
        {
            success = true;
            continue;
        }
        else
        {
            success = false;
            break;
        }
    }

    return success;
}

fn main()
{
    let input : Vec<String> = read_input();

    for s in input
    {
        if str_is_funny(&s)
        {
            println!("Funny");
        }
        else
        {
            println!("Not Funny");
        }
    }
}
