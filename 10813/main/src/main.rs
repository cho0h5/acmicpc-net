fn input() -> (usize, usize) {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let input = s.trim().split(" ");
    let input: Vec<usize> = input.into_iter().map(|x| x.parse::<usize>().unwrap()).collect();
    return (input[0], input[1]);
}

fn main() {
    let mut array = [0; 101];
    let (n, m) = input();
    for i in 1..=n {
        array[i] = i as i32;
    }
    for _ in 0..m {
        let (i, j) = input();
        let tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    for i in 1..=n {
        print!("{} ", array[i]);
    }
}

