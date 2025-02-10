var maxScoreWords = function(words, letters, score) {
    let letterCount = new Array(26).fill(0);

    // Contar quantas vezes cada letra aparece na lista de letras disponíveis
    for (let ch of letters) {
        letterCount[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    // Função de backtracking para testar todas as combinações possíveis de palavras
    function backtrack(index, currentScore, letterFreq) {
        if (index === words.length) {
            return currentScore;
        }

        // Tentar não pegar a palavra atual
        let maxScore = backtrack(index + 1, currentScore, letterFreq);

        // Verificar se podemos pegar a palavra atual
        let word = words[index];
        let tempFreq = [...letterFreq];
        let wordScore = 0;
        let isValid = true;

        for (let ch of word) {
            let charIdx = ch.charCodeAt(0) - 'a'.charCodeAt(0);
            if (tempFreq[charIdx] > 0) {
                tempFreq[charIdx]--;
                wordScore += score[charIdx];
            } else {
                isValid = false;
                break;
            }
        }

        // Se a palavra for válida, tentamos incluí-la na solução
        if (isValid) {
            maxScore = Math.max(maxScore, backtrack(index + 1, currentScore + wordScore, tempFreq));
        }

        return maxScore;
    }

    return backtrack(0, 0, letterCount);
};
