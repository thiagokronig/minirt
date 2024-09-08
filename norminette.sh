#/bin/bash

install() {
    if [ -d "norminette" ]; then
        return
    fi
    python3 -m venv norminette
    (
        source "norminette/bin/activate"
        python3 -m pip install --upgrade pip setuptools
        python3 -m pip install norminette
    )
}

run() {
    (
        source "norminette/bin/activate"
        norminette/bin/norminette
    )
}

main() {
    set -euo pipefail

    install
    run
}

main "$@"
