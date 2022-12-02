use std::path::Path;
use std::fs::File;
use std::io::{BufReader, BufRead};
use std::env;

fn main() {
    let mut dir = env::current_dir().unwrap();
    dir.pop();
    let path = dir.display().to_string() + "\\Input.txt";
    let n:u32 = 3;
    let lines = lines_from_file(path);
    let mut calories_vector:Vec<u32> = Vec::new();
    let mut curr_calories: u32 = 0;
    for line in lines {
        if line != ""{

            let value:u32 = line.parse().unwrap();
            curr_calories += value;
        }else {
            calories_vector.push(curr_calories);
            curr_calories = 0;
        }
    }

    calories_vector.sort();

    let top_n_sum:u32 = calories_vector.iter().rev().take(n as usize).sum();

    println!("Sum of top {} calories held: {}",n , top_n_sum);
}


fn lines_from_file(filename: impl AsRef<Path>) -> Vec<String> {
    let file = File::open(filename).expect("no such file");
    let buf = BufReader::new(file);
    buf.lines().map(|l| l.expect("Could not parse line"))
        .collect()
}
