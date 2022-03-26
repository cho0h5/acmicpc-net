use std::convert::From;
use std::fmt::{Display, Formatter, Result};

#[derive(Debug)]
enum Direction {
    N,
    E,
    S,
    W,
}

use Direction::*;

impl From<i32> for Direction{
    fn from(item: i32) -> Self {
        match item % 4 {
            0 => N,
            1 => E,
            2 => S,
            3 => W,
            _ => N,
        }
    }
}

impl Display for Direction {
    fn fmt(&self, f: &mut Formatter) -> Result {
        match self {
            N =>  write!(f, "0"), 
            E =>  write!(f, "1"), 
            S =>  write!(f, "2"),
            W =>  write!(f, "3"),
        }
    }
}

#[derive(Debug)]
struct Robot {
    x: i32,
    y: i32,
    d: Direction,
}

impl Robot {
    fn R(&mut self, count: i32) {
        let d = self.d.to_string().parse::<i32>().unwrap();
        self.d = Direction::from(d + count);
    }

    fn L(&mut self, count: i32) {
        let d = self.d.to_string().parse::<i32>().unwrap();
        self.d = Direction::from(d - count);
    }

    fn F(&mut self, count: i32) {
        match self.d {
            N => self.y += count,
            E => self.x += count,
            S => self.y -= count,
            W => self.x -= count,
        }
    }
}

fn main() {
    let mut robot1 = Robot {
        x: 3,
        y: 2,
        d: W,
    };

    println!("{:?}", robot1);
    robot1.R(2);
    println!("{:?}", robot1);
    robot1.L(1);
    println!("{:?}", robot1);
    robot1.F(10);
    println!("{:?}", robot1);
    robot1.R(1);
    println!("{:?}", robot1);
    robot1.F(2);
    println!("{:?}", robot1);
}
