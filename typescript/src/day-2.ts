import *  as fs from "fs";
import * as readline from "readline";

async function processFile(): Promise<void> {
	try {
		const filePath: string = "./input.txt";

		const fileStream = fs.createReadStream(filePath);

		const rl = readline.createInterface({
			input: fileStream,
			crlfDelay: Infinity,
		});

		for await (const line of rl) {
			let prev: any;
			let flag = true;
			let count = 0;
			let dir = 0;
			for (const num of line) {
				prev = num;
			}
			for (const num of line) {
				let diff = prev - num;
				if (Math.abs(diff) < 1 || Math.abs(diff) > 3) {
					flag = false;
					break;
				}
				let curDir = (diff > 0) ? 1 : -1;
				if (dir != 0 && dir != curDir) {
					flag = false;
					break;
				}
				dir = curDir;
				prev = num;
			}
			if (flag) {
				count++;
			}

			console.log("end of line")
		}
		console.log("done");
	}
	catch (error) {
		console.error(`Error reading file: ${error.message}`);
	}
	return;
}
processFile();

