class EventEmitter {
    constructor() {
        this.obj = {};
    }
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if (!this.obj[eventName]) {
            this.obj[eventName] = [];
        }
        this.obj[eventName].push(callback);
        return {
            unsubscribe: () => {
                const index = this.obj[eventName].indexOf(callback);
                if (index !== -1) {
                    this.obj[eventName].splice(index, 1);
                }
                return undefined;
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        if (!this.obj[eventName]) return [];
        return this.obj[eventName].map(callback => callback(...args));
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */