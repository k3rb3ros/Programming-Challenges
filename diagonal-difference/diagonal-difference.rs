use std::io;

struct Matrix
{
    size: usize,
    rows: Vec<Vec<i32>>
}

fn read_input() -> Matrix
{
    let mut input = String::new();
    let mut m : Matrix = Matrix { size: 0, rows: Vec::new() };

    //the first line of input is the size of the matrix
    match io::stdin().read_line(&mut input)
    {
        Ok(..) =>
        {
            let trimmed = input.trim();
            match trimmed.parse::<usize>()
            {
                Ok(i) => m.size = i,
                Err(..) => println!("Invalid input encountered expected first line to be an integer"),
            }
        }
        Err(error) => { println!("error: {}", error); }
    }

    //each line after that is a row with there being size rows
    for i in 0..m.size
    {
        input = String::new();
        match io::stdin().read_line(&mut input)
        {
            Ok(..) => 
            {
                //Fuck you rust for making this harder then it needed to be
                if input.char_indices().rev().nth(0).unwrap() == (input.len()-1, '\n') { input.pop(); }
                let row = input.split(" ").filter_map(|s| s.parse::<i32>().ok()).collect::<Vec<i32>>();
                //add it to the matrix
                m.rows.push(row);
            }
            Err(error) => { println!("error: {}", error); }
        }
    }

    return m;
}

fn sum_diagonals(m: Matrix) -> i32
{
    let mut pri_diag_ind: usize = 0;
    let mut sec_diag_ind: usize = m.size-1;
    let mut pri_diag_sum: i32 = 0;
    let mut sec_diag_sum: i32 = 0;

    for r in 0..m.size
    {
        pri_diag_sum += m.rows[r][pri_diag_ind];
        sec_diag_sum += m.rows[r][sec_diag_ind];
        pri_diag_ind += 1;
        if sec_diag_ind > 0 { sec_diag_ind -= 1 } //for loops in rust appear to be post condition evaluation under the hood

        //for i in 0..m.size { print!("{} ", m.rows[r][i]); }
        //print!("\n");
    }

    return (pri_diag_sum-sec_diag_sum).abs();
}

fn main()
{
    let matrix = read_input();
    println!("{}", sum_diagonals(matrix));
}
