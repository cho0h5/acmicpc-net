use std::io;
use std::cmp::max;

fn input() -> (i32, i32, i32, i32) {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let numbers: Vec<i32> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse::<i32>().unwrap())
        .collect();
    (numbers[0], numbers[1], numbers[2], numbers[3])
}

fn get_start(level: i32) -> i32 {
    if level == 0 {
        0
    } else {
        (level * 2 - 1).pow(2)
    }
}

fn sol(x: i32, y: i32) -> i32 {
    let level = max(x.abs(), y.abs());

    let offset = if x == 0 && y == 0 {
        1
    } else if x == -level {
        level * 2 + (level - y)
    } else if x == level {
        level * 6 + (y - -level)
    } else if y == -level {
        level * 4 + (x - -level)
    } else if y == level {
        level * 0 + (level - x)
    } else {
        panic!("what the heck!");
    };

    let start = get_start(level);

    return offset + start;
}

fn main() {
    let mut output = String::new();

    let (r1, c1, r2, c2) = input();

    for i in r1..=r2 {
        for j in c1..=c2 {
            output.push_str(&sol(i, j).to_string());
            output.push(' ');
        }
        output.push('\n');
    }

    println!("{}", output);
}
