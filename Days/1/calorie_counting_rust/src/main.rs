use std::path::Path;
use std::fs::File;
use std::io::{BufReader, BufRead};
use std::cmp;

fn main() {
    let path = "..Input.txt";
    let lines = lines_from_file(path);
    let mut highest_calories: u32 = 0;
    let mut curr_calories: u32 = 0;
    for line in lines {
        if line != ""{
            let value:u32 = line.parse().unwrap();
            curr_calories += value;
        }else {
            highest_calories = cmp::max(curr_calories, highest_calories);
            curr_calories = 0;
        }
    }

    println!("Most Calories Held: {}",highest_calories);
}


fn lines_from_file(filename: impl AsRef<Path>) -> Vec<String> {
    let file = File::open(filename).expect("no such file");
    let buf = BufReader::new(file);
    buf.lines().map(|l| l.expect("Could not parse line"))
        .collect()
}
