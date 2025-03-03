
/*

import * as fs from "fs";
import * as readline from "readline";

let grid: string[][] = [];

async function processFile(): Promise<void> {

	try {
		const filePath: string = "./input.txt";
		const fileStream = fs.createReadStream(filePath);
		const rl = readline.createInterface({ input: fileStream, crlfDelay: Infinity });

		for await (const line of rl) {
			grid.push(line.split(""));
		}
		console.log("grid created")
		//find_XMAS()
		//find_X();

	} catch (error) {
		console.error("error: ", error)
	}
}
processFile();
 */

function getInput(): string {
	return `MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX`;
}

const grid = getInput().split('\n').map(row => row.split(''));
find_XMAS()
find_X();


function find_X() {
	let x_count = 0;
	/*
	 (1,1)		(1,3)
		(2,2)
	 (1,3)		(3,3)
	 */

	for (let row = 1; row < grid.length - 1; row++) {
		for (let col = 1; col < grid[row].length - 1; col++) {
			if (grid[row][col] === 'A') {
				if (
					(grid[row - 1][col - 1] === 'M' && grid[row + 1][col + 1] === 'S') ||
					(grid[row - 1][col - 1] === 'S' && grid[row + 1][col + 1] === 'M')
				) {
					if (
						(grid[row + 1][col - 1] === 'M' && grid[row - 1][col + 1] === 'S') ||
						(grid[row + 1][col - 1] === 'S' && grid[row - 1][col + 1] === 'M')

					) {
						x_count++;
					}

				}
			}
		}
	}

	console.log(x_count);
}


function find_XMAS() {

	const directions = [
		{ dr: 0, dc: 1 },  // Right
		{ dr: 0, dc: -1 }, // Left
		{ dr: 1, dc: 0 },  // Down
		{ dr: -1, dc: 0 }, // Up
		{ dr: 1, dc: 1 },  // Down-Right
		{ dr: 1, dc: -1 }, // Down-Left
		{ dr: -1, dc: 1 }, // Up-Right
		{ dr: -1, dc: -1 } // Up-Left
	];

	let count: number = 0;

	for (let row = 0; row < grid.length; row++) {
		for (let col = 0; col < grid[row].length; col++) {

			for (const dir of directions) {
				let isValid = true;

				for (let step = 0; step < 4; step++) {
					const newRow = row + dir.dr * step;
					const newCol = col + dir.dc * step;

					if (newRow < 0 || newRow >= grid.length || newCol < 0 || newCol >= grid[row].length) {
						isValid = false;
						break;
					}
				}

				if (!isValid) continue;

				const word = [
					grid[row + dir.dr * 0][col + dir.dc * 0],
					grid[row + dir.dr * 1][col + dir.dc * 1],
					grid[row + dir.dr * 2][col + dir.dc * 2],
					grid[row + dir.dr * 3][col + dir.dc * 3]
				].join('');

				if (word === 'XMAS') {
					console.log(word)
					count++;
				}
			}
		}
	}

	console.log(count);
}

