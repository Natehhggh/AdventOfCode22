use std::path::Path;
use std::fs::{File};
use std::io::{BufReader, BufRead};
use std::i8;
use std::env;

static RESULT_MATRIX: &'static [[i8;3];3] = &[[0,2,1]
                                             ,[1,0,2]
                                             ,[2,1,0]];

static RESULT_SCORES_MATRIX: &'static [[i64;3]] = &[[3,6,0]
                                                  ,[3,0,6]];


fn main() {
    let mut dir = env::current_dir().unwrap();
    dir.pop();
    let path = dir.display().to_string() + "\\Input.txt";
    //TODO: why will this not work it's litterally the same as day 1.....
    //let path = "..Input.txt";
    let lines = lines_from_file(path);
    let player_num:i8 = 1;
    let score = get_player_score(player_num, lines);

    println!("Player {} score {}", player_num, score)
}


// TODO: refactor all days to 1 project for code reuse. Im going to need a lot of file reading
fn lines_from_file(filename: impl AsRef<Path>) -> Vec<String> {
    let file = File::open(filename).expect("no such file");
    let buf = BufReader::new(file);
    buf.lines().map(|l| l.expect("Could not parse line"))
        .collect()
}


fn get_thrown_idx_p1(thrown: char) -> i32{
    return (thrown as i32 - 2) % 3;
}


fn get_thrown_idx_p2(thrown: char) -> i32{
    return (thrown as i32 + 2) % 3;
}

fn get_thrown_idx_p2_part_2(thrown:Vec<char>) -> i32{
    let win_state = (thrown[2] as i32 + 2) % 3 - 1;

    return get_mod((thrown[0] as i32 - 2) + win_state, 3);
}

fn get_thrown_idx(thrown:Vec<char>) -> [i32; 2]{
    let thrown_indecies:[i32; 2] = [get_thrown_idx_p1(thrown[0]), get_thrown_idx_p2(thrown[2])];
    return thrown_indecies
}

fn get_thrown_idx_part_2(thrown:Vec<char>) -> [i32; 2]{
    let thrown_indecies:[i32; 2] = [get_thrown_idx_p1(thrown[0]), get_thrown_idx_p2_part_2(thrown)];
    return thrown_indecies
}

fn get_thrown_score(thrown_idx:i32) -> i64{
    return (thrown_idx + 1).into();
}

fn get_game_result(thrown:[i32; 2]) -> i8{
    return RESULT_MATRIX[thrown[0] as usize][thrown[1] as usize];
}

fn get_game_score(result:i8, player_num:i8) -> i64{
    return RESULT_SCORES_MATRIX[player_num as usize][result as usize];
}


fn get_mod(x:i32, m:i32)-> i32{
    return (x % m + m) % m;
}

//TODO: refactor into operating on set of p1, and set of p2 moves
fn get_player_score(player_num:i8, lines:Vec<String>) -> i64{
    let mut player_score:i64 = 0;
    for line in lines{
        let strategy_plays:Vec<char> = line.chars().collect();
        //let thrown_indecies = get_thrown_idx(strategy_plays);
        let thrown_indecies = get_thrown_idx_part_2(strategy_plays);

        let result:i8 = get_game_result(thrown_indecies);
        

        player_score += get_thrown_score(thrown_indecies[player_num as usize]);
        player_score += get_game_score(result, player_num);
    }

    return player_score;
}
