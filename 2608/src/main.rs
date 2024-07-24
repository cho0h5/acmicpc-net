use std::io;

fn input() -> io::Result<(String, String)> {
    let mut rome_number1 = String::new();
    let mut rome_number2 = String::new();

    io::stdin().read_line(&mut rome_number1)?;
    io::stdin().read_line(&mut rome_number2)?;

    return Ok((rome_number1.trim().to_string(), rome_number2.trim().to_string()));
}

fn convert_rome_to_arabic(rome: String) -> i32 {
    let mut arabic = 0;
    let rome = rome.as_bytes();


    let mut i = 0;
    while i < rome.len() {
        match rome[i] {
            b'V' => arabic += 5,
            b'L' => arabic += 50,
            b'D' => arabic += 500,
            b'I' => {
                if i + 1 == rome.len() {
                    arabic += 1;
                } else if rome[i + 1] == b'V' {
                    arabic += 4;
                    i += 1;
                } else if rome[i + 1] == b'X' {
                    arabic += 9;
                    i += 1;
                } else {
                    arabic += 1;
                }
            },
            b'X' => {
                if i + 1== rome.len() {
                    arabic += 10;
                } else if rome[i + 1] == b'L' {
                    arabic += 40;
                    i += 1;
                } else if rome[i + 1] == b'C' {
                    arabic += 90;
                    i += 1;
                } else {
                    arabic += 10;
                }
            },
            b'C' => {
                if i + 1== rome.len() {
                    arabic += 100;
                } else if rome[i + 1] == b'D' {
                    arabic += 400;
                    i += 1;
                } else if rome[i + 1] == b'M' {
                    arabic += 900;
                    i += 1;
                } else {
                    arabic += 100;
                }
            },
            b'M' => arabic += 1000,
            _ => (),
        }
        i += 1;
    }

    arabic
}

fn rome1000(digit: i32) -> &'static str {
    match digit / 1000 {
        0 => "",
        1 => "M",
        2 => "MM",
        3 => "MMM",
        _ => panic!("no way"),
    }
}

fn rome100(digit: i32) -> &'static str {
    match (digit / 100) % 10 {
        0 => "",
        1 => "C",
        2 => "CC",
        3 => "CCC",
        4 => "CD",
        5 => "D",
        6 => "DC",
        7 => "DCC",
        8 => "DCCC",
        9 => "CM",
        _ => panic!("no way"),
    }
}

fn rome10(digit: i32) -> &'static str {
    match (digit / 10) % 10 {
        0 => "",
        1 => "X",
        2 => "XX",
        3 => "XXX",
        4 => "XL",
        5 => "L",
        6 => "LX",
        7 => "LXX",
        8 => "LXXX",
        9 => "XC",
        _ => panic!("no way"),
    }
}

fn rome1(digit: i32) -> &'static str {
    match digit % 10 {
        0 => "",
        1 => "I",
        2 => "II",
        3 => "III",
        4 => "IV",
        5 => "V",
        6 => "VI",
        7 => "VII",
        8 => "VIII",
        9 => "IX",
        _ => panic!("no way"),
    }
}

fn convert_arabic_to_rome(arabic: i32) -> String {
    let mut rome = String::new();

    rome.push_str(rome1000(arabic));
    rome.push_str(rome100(arabic));
    rome.push_str(rome10(arabic));
    rome.push_str(rome1(arabic));

    rome
}

fn main() -> io::Result<()> {
    let (rome_number1, rome_number2) = input()?;

    let arabic_number1 = convert_rome_to_arabic(rome_number1);
    let arabic_number2 = convert_rome_to_arabic(rome_number2);

    let sum = arabic_number1 + arabic_number2;
    println!("{}", sum);
    println!("{}", convert_arabic_to_rome(sum));

    Ok(())
}
