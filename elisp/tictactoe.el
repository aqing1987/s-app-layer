;; tictactoe.el -- play tic tac toe in Emacs
;; M-x eval-buffer
;; M-x tictactoe
;; Use Space To Move

(defun tictactoe ()
  "Start playing tic tac toe"
  (interactive)
  (switch-to-buffer "tictactoe")
  (tictactoe-mode)
  (tictactoe-init))

(defun tictactoe-init ()
  "Start a new game of tic tac toe."
  (setq *tictactoe-board*
        (make-vector (* *tictactoe-size* *tictactoe-size*) ?\.))
  (tictactoe-print-board)
  (setq *tictactoe-current-player* ?\X))

(defun tictactoe-print-board ()
  "print to the board"
  (let ((inhibit-read-only t))
    (erase-buffer)
    (dotimes (row *tictactoe-size*)
      (dotimes (column *tictactoe-size*)
        (insert (tictactoe-get-square row column)))
      (insert "\n")))
  )

(defun tictactoe-get-square (row column)
  "Get the value in the (row, column) square."
  (elt *tictactoe-board*
       (+ column
          (* row
             *tictactoe-size*)))
  )

(defun tictactoe-set-square (row column value)
  "Set the value in the (row, column) square to value."
  (aset *tictactoe-board*
        (+ column
           (* row
              *tictactoe-size*))
        value)
  )

(defun tictactoe-mark ()
  "Mark the current square"
  (interactive)
  (let ((row (1- (line-number-at-pos)))
        (column (current-column)))
    (tictactoe-set-square row column *tictactoe-current-player*))
  (tictactoe-print-board)
  (when (tictactoe-game-has-been-won)
    (message "Congrats! Player %c won!" *tictactoe-current-player*))
  (tictactoe-swap-players)
  )

(defun tictactoe-game-has-been-won ()
  "Returns t if the game has been won, nil otherwise"
  (or (tictactoe-diagonal-win)
      (tictactoe-row-win)
      (tictactoe-column-win)))

(defun tictactoe-diagonal-win ()
  (or (tictactoe-all-same-player
       (tictactoe-get-square 0 0)
       (tictactoe-get-square 1 1)
       (tictactoe-get-square 2 2))

      (tictactoe-all-same-player
       (tictactoe-get-square 0 2)
       (tictactoe-get-square 1 1)
       (tictactoe-get-square 2 0))))

(defun tictactoe-row-win ()
  (let ((has-won nil))
    (dotimes (row *tictactoe-size*)
      (when (tictactoe-all-same-player
             (tictactoe-get-square row 0)
             (tictactoe-get-square row 1)
             (tictactoe-get-square row 2))
        (setq has-won t)))
    has-won))

(defun tictactoe-column-win ()
  (let ((has-won nil))
    (dotimes (column *tictactoe-size*)
      (when (tictactoe-all-same-player
           (tictactoe-get-square 0 column)
           (tictactoe-get-square 1 column)
           (tictactoe-get-square 2 column))
      (setq has-own t)))
    has-won))

(defun tictactoe-all-same-player (sq1 sq2 sq3)
  (and (tictactoe-is-a-player sq1)
       (char-equal sq1 sq2)
       (char-equal sq2 sq3)))

(defun tictactoe-is-a-player (square)
  (or (char-equal square ?\X)
      (char-equal square ?\O)))

(defun tictactoe-swap-players ()
  "Make it the other player's turn"
  (setq *tictactoe-current-player*
        (if (char-equal *tictactoe-current-player* ?\X)
            ?\O
          ?\X)))

(define-derived-mode tictactoe-mode special-mode
  "tic-tac-toe"
  (define-key tictactoe-mode-map (kbd "SPC") 'tictactoe-mark))

(defvar *tictactoe-board* nil
  "The board itself.")

(defvar *tictactoe-current-player* nil
  "The character representing the current player.")

(defconst *tictactoe-size* 3
  "the size of the board - both height and width.")