use std::io;
use std::io::prelude::*;

struct AppleOrangeProblem
{
    s: i32,
    t: i32,
    a: i32,
    b: i32,
    apples: Vec<i32>,
    oranges: Vec<i32>,
    a_ans: i32,
    o_ans: i32
}

fn read_input() -> Vec<String>
{
    let mut linecount = 0usize;
    let stdin = io::stdin();
    let mut input: Vec<String> = vec![];
    for line in stdin.lock().lines()
    {
        linecount = linecount + 1;
        input.push(line.unwrap());
    }

    return input;
}

fn parse_string_arr_to_uint_arr(line: & Vec<&str>, data: &mut Vec<i32>)
{
    for num in line
    {
        data.push(num.parse::<i32>().unwrap());
    }
}

fn parse_two_uints(line: & Vec<&str>, one: &mut i32, two: &mut i32)
{
    *one = line[0].parse::<i32>().unwrap();
    *two = line[1].parse::<i32>().unwrap();
}

fn parse_input(input: & Vec<String>, problem: &mut AppleOrangeProblem)
{
    let mut count = 0i32;
    for string in input
    {
        let split: Vec<&str> = string.split(" ").collect();
        count = count + 1;
        match count
        {
            1 => parse_two_uints(&split, &mut problem.s, &mut problem.t),
            2 => parse_two_uints(&split, &mut problem.a, &mut problem.b),
            // 3 contains size of arrays to follow and is ignored
            4 => parse_string_arr_to_uint_arr(&split, &mut problem.apples),
            5 => parse_string_arr_to_uint_arr(&split, &mut problem.oranges),
            _ => (),
        }
    }
}

fn solve_problem(problem: &mut AppleOrangeProblem)
{
    // calculate if an apple lands on the house
    for a in &problem.apples
    {
        let a_land = problem.a + a;

        if (a_land >= problem.s && a_land <= problem.t)
        {
            problem.a_ans = problem.a_ans + 1;
        }
    }

    // calculate if an orange lands on the house
    for o in &problem.oranges
    {
        let o_land = problem.b + o;

        if (o_land >= problem.s && o_land <= problem.t)
        {
            problem.o_ans = problem.o_ans + 1;
        }
    }

    println!("{}", problem.a_ans);
    println!("{}", problem.o_ans);
}

fn main()
{
    let input = read_input();
    let mut problem = AppleOrangeProblem{ s:0, t:0, a:0, b:0, apples:vec![], oranges:vec![], a_ans:0, o_ans:0 };
    parse_input(&input, &mut problem);
    solve_problem(&mut problem);
}
