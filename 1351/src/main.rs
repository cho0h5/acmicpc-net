fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let mut line = line.split_whitespace();
    let n: usize = line.next().unwrap().parse().unwrap();
    let p: usize = line.next().unwrap().parse().unwrap();
    let q: usize = line.next().unwrap().parse().unwrap();
    let mut vector = vec![1];

    for i in 1..=n {
        vector.push(vector[i / p] + vector[i / q]);
    }
    println!("{}", vector.last().unwrap());
}
